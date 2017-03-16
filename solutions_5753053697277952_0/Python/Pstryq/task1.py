class Solution(object):
    def __init__(self):
        self._test_cases = self._read_int()

    def solve(self):
        for case_index in xrange(1, self._test_cases + 1):
            test_input = self._read_input_for_single_test_case()
            result = self._solve_single_test_case(test_input)
            self._process_single_test_case_output(case_index, result)

    def _read_input_for_single_test_case(self):
        n = self._read_int()
        arr = self._read_int_array()
        sen_dict = {}
        for i in xrange(n):
            if arr[i] not in sen_dict:
                sen_dict[arr[i]] = [chr(i + 65)]
            else:
                sen_dict[arr[i]].append(chr(i + 65))

        return n, sen_dict

    def _solve_single_test_case(self, test_input):
        n, senators = test_input
        result = []
        m = max(senators.keys())
        while m > 0:
            result.extend([''.join(senators[m][i:i + 2]) for i in xrange(0, len(senators[m]), 2)][::-1])
            m -= 1
            if m not in senators.keys():
                senators[m] = []
            senators[m].extend(senators[m + 1])

        return ' '.join(result)

    @staticmethod
    def _process_single_test_case_output(case_index, result):
        print 'Case #{}: {}'.format(case_index, result)

    @staticmethod
    def _read_int():
        return int(raw_input().strip())

    @staticmethod
    def _read_int_array():
        return map(int, raw_input().strip().split())

    @staticmethod
    def _read_string():
        return raw_input().strip()

    @staticmethod
    def _read_string_array():
        return raw_input().strip().split()


solution = Solution()
solution.solve()
