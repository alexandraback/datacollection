import os, sys


class ReadWrite:
    def __init__(self, file_name=None, verbose=True):
        self.verbose = verbose
        if file_name is None:
            self.in_file = sys.stdin
            self.out_file = sys.stdout
        else:
            self.in_file = open(file_name)
            self.out_file = open(os.path.splitext(file_name)[0] + '.out', 'w')
        self.case_idx = 1


    def msg(self, output, end='\n'):
        sys.stderr.write(str(output) + end)


    def read_line(self, *types, all=None):
        words = self.in_file.readline().strip().split()
        if all is not None:
            return [all(w) for w in words]
        if len(types) == 0:
            return words
        assert (len(words) == len(types))
        if len(types) == 1:
            return types[0](words[0])
        return [t(w) for t, w in zip(types, words)]


    def write_case(self, output, true="YES", false="NO", join='\n'):
        pfx = "Case #%d:" % self.case_idx
        self.case_idx += 1
        if isinstance(output, list):
            text = join.join([pfx] + output)
        elif isinstance(output, bool):
            text = pfx + ' ' + (true if output else false)
        else:
            text = pfx + ' ' + str(output)
        self.out_file.write(text + '\n')
        if self.verbose:
            self.msg(text)
        else:
            self.msg(pfx)


from collections import namedtuple

from enum import Enum


class HeapType(Enum):
    """
    The type of a Heap.  A min heap has the smallest item on top.  A max
    heap has the largest item on top.
    """
    min = -1
    max = 1


Elem = namedtuple('Elem', 'key item')
"""
A tuple used to store (key, item) pairs when Heap uses a key_func.  This
allows fast heap operations even when the key function is costly to compute.
"""


class AbstractHeap(object):
    """Abstract base class for heap collections.

    The items to be stored on the heap must either be comparable with < and >,
    or a key function must be supplied that returns a value that can be
    compared.  In either case, the key value must not change as long as the
    item is in the heap, as the placement of the item within the heap is
    determined by its key value.

    Note that a heap can only be merged with another heap of the same type
    that has the identical key_func and order.  Use the ``new_heap()`` method
    to create an empty heap with the same properties.
    """

    def __init__(self, *,
                 key_func=None,
                 heap_type=HeapType.min,
                 is_valid_func=None):
        """
        Create a new heap
        :param key_func: the function used to create a key from an item,
            or None, if the heap should use the item itself as the key.
        :type key_func: item -> key type
        :param heap_type: the type of heap to create (max or min)
        :type heap_type: HeapType
        :param is_valid_func: A function used to determine if an item is valid.
          only valid items are returned by pop, pop_all, and top.  If this
          parameter is None, all items are considered valid.
          This allows the user to quickly invalidate items that are on the
          heap without actually removing them from the heap (which can be a
          costly operation).
        :type is_valid_func: None | (item) -> bool
        """
        self._key_func = key_func
        self._heap_type = heap_type
        self._is_valid_func = is_valid_func
        if self._heap_type is HeapType.min:
            self._keys_in_order = lambda a, b: a < b
        elif self._heap_type is HeapType.max:
            self._keys_in_order = lambda a, b: a > b
        else:
            raise ValueError("Invalid value for heap_type: %s.  Must be "
                             "HeapType.min or HeapType.max" % str(heap_type))
        self_len = 0

    def _make_elem(self, item):
        if self._key_func is None:
            return item
        return Elem(self._key_func(item), item)

    def _is_empty(self):
        """
        Implement this function in a concrete subclass.  it will be used by
        the `is_empty` property.  This function should not consider whether
        the top element is valid or not.
        """
        raise NotImplementedError()

    def _top_elem(self):
        """
        Implement this function in a concrete subclass.  it will be used by
        the `top` property to return the top item of the heap.  It should not
        consider whether the top element is valid or not.
        """
        raise NotImplementedError()

    def _delete_top(self):
        """
        Implement this function in a concrete subclass.  It must delete the
        top element from the heap (whether it is valid or not.
        """
        raise NotImplementedError()

    def _delete_until_valid(self):
        if self._is_valid_func is None:
            return
        while not self._is_empty() and not self._is_valid_func(
                self._top_elem()):
            self._delete_top()

    @property
    def is_empty(self):
        """
        :return: True if the heap is empty
        :rtype: bool
        """
        self._delete_until_valid()
        return self._is_empty()

    @property
    def top(self):
        """
        :return: the element on top of the heap
        :rtype: bool
        """
        self._delete_until_valid()
        if self._is_empty():
            raise ValueError("Heap is empty.")
        t = self._top_elem()
        if self._key_func is None:
            return t
        return t.item

    def new_heap(self):
        """
        Create an empty heap with the same key function and sort order as
        this one.
        :return: the new heap
        :rtype: same type as this heap
        """
        raise NotImplementedError()

    def add(self, item):
        """
        Add an item to the heap
        :param item: The item to add to the heap
        """
        raise NotImplementedError()

    def add_all(self, items):
        """
        Add several items to the heap
        :param items: the items to add
        :type items: Iterable
        """
        for i in items:
            self.add(i)

    def pop(self):
        """
        Remove and return the item on top of the heap.

        :return: the top item on the heap
        """
        i = self.top
        self._delete_top()
        return i

    def pop_all(self):
        """
        Pop all of the items off the heap and return them
        :return: all the items on the heap
        :rtype: list
        """
        result = list()
        while not self.is_empty:
            result.append(self.pop())
        return result

    def pop_until(self, until_func):
        """
        Pop items off the heap until until_func(elem) is True.

        :param until_func: the function
        :type until_func: (elem) -> bool
        :return: all the items on the heap that occur before until_func is True.
        :rtype: list
        """
        result = []
        while not self.is_empty and not until_func(self.top):
            result.append(self.pop())
        return result

    def merge(self, other):
        """
        Merge other with this heap.

        The items in other will be removed from it; other will be empty when
        this member function is done.
        :param other: another heap with the same key_func and sort order as
        this heap.
        :type other: same as this heap
        """
        raise NotImplementedError()

    def clear(self):
        """
        Remove and discard all the items in this heap.
        """
        raise NotImplementedError()


class PairingSubHeap(object):
    def __init__(self, elem, sub_heaps=None):
        if sub_heaps is None:
            sub_heaps = list()
        self._elem = elem
        self._sub_heaps = [s for s in sub_heaps]

    def clear(self):
        for i in self._sub_heaps:
            i.clear()


class PairingHeap(AbstractHeap):
    def __init__(self, *,
                 key_func=None,
                 heap_type=HeapType.min,
                 is_valid_func=None):
        super().__init__(key_func=key_func,
                         heap_type=heap_type,
                         is_valid_func=is_valid_func)
        self._root = None


    def new_heap(self):
        return PairingHeap(key_func=self._key_func, heap_type=self._heap_type)

    def _merge_subheaps(self, h1, h2):
        if h1 is None:
            return h2
        if h2 is None:
            return h1
        if self._key_func is None:
            k1, k2 = h1._elem, h2._elem
        else:
            k1, k2 = k1, k2 = h1._elem.key, h2._elem.key
        if self._keys_in_order(k1, k2):
            return PairingSubHeap(h1._elem, [h2] + h1._sub_heaps)
        return PairingSubHeap(h2._elem, [h1] + h2._sub_heaps)

    def _insert_subheaps(self, sub_heap, heap):
        return self._merge_subheaps(sub_heap, heap)

    def _delete_top_sub_heap(self, sub_heap):
        assert sub_heap is not None
        return self._merge_pairs(sub_heap._sub_heaps)

    def _delete_top(self):
        self._root = self._delete_top_sub_heap(self._root)

    def _merge_pairs(self, subheaps):
        n = len(subheaps)
        if n == 0:
            return None
        if n == 1:
            return subheaps[0]
        return self._merge_subheaps(self._merge_subheaps(subheaps[0],
                                                         subheaps[1]),
                                    self._merge_pairs(subheaps[2:]))

    def _top_elem(self):
        return self._root._elem

    def _is_empty(self):
        return self._root is None

    def add(self, item):
        if self._key_func is None:
            e = item
        else:
            e = self._make_elem(item)
        s = PairingSubHeap(e)
        self._root = self._insert_subheaps(s, self._root)

    def merge(self, other):
        if not isinstance(other, PairingHeap):
            raise ValueError("Can only merge with another PairingHeap")
        if not (self._heap_type == other._heap_type):
            raise ValueError("Can only merge heaps with the same sort order")
        if not self._key_func == other._key_func:
            raise ValueError("Can only merge heaps with identical key "
                             "functions.")
        self._root = self._merge_subheaps(self._root, other._root)
        other._root = None

    def clear(self):
        self._root.clear()
        self._root = None

    def __sub_heap_to_str(self, sub_heap):
        f = lambda e: str(e)
        if self._key_func is not None:
            f = lambda e: str(e.item)
        if len(sub_heap._sub_heaps) == 0:
            return '[%s : *]' % f(sub_heap._elem)
        return '[%s : %s]' % (f(sub_heap._elem),
                              ' '.join(self.__sub_heap_to_str(s) for s in
                                       sub_heap._sub_heaps))

    def __str__(self):
        if self.is_empty:
            return '*'
        return self.__sub_heap_to_str(self._root)


def which_barber(place, minutes):
    free_barbers = PairingHeap()
    for i in range(len(minutes)):
        free_barbers.add(i)
    events = PairingHeap()
    now = 0
    cycle = []
    nfb = len(minutes)
    nb = nfb
    while True:
        while not events.is_empty and events.top[0] <= now:
            (now, barber) = events.pop()
            free_barbers.add(barber)
            nfb += 1
        if free_barbers.is_empty:
            (now, barber) = events.pop()
            free_barbers.add(barber)
            nfb += 1
            while not events.is_empty and events.top[0] <= now:
                (now, barber) = events.pop()
                free_barbers.add(barber)
                nfb += 1
        if events.is_empty and nfb == nb and len(cycle) > 0:
            break  # we've completed a cycle

        # print((place, nfb, nb, str(events), str(free_barbers)))
        b = free_barbers.pop()
        cycle.append(b)
        nfb -= 1
        if place == 0:
            return b
        events.add((now + minutes[b], b))
        place -= 1
    i = place % len(cycle)
    return cycle[i]


if __name__ == '__main__':
    input_name = sys.argv[1] if len(sys.argv) > 1 else 'B-small-attempt0.bin'
    rw = ReadWrite(input_name)
    T = rw.read_line(int)
    for t in range(T):
        B, N = rw.read_line(int, int)
        M = rw.read_line(all=int)
        rw.write_case(which_barber(N - 1, M) + 1)
