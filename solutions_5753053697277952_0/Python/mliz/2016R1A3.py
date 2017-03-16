with open("A-small-attempt1.in", "r") as data:
    cases = int(data.readline())
    with open("A-small-attempt1.out", "w") as result:
        for i in range(cases):
            parties = int(data.readline())
            nums = list(map(int, data.readline().split(" ")))
            result.write("Case #" + str(i+1) + ": ")
            while(any(x > 0 for x in nums)):
                if sum(nums) == 2:
                    for j in range(2):
                        result.write(chr(ord("A") + nums.index(max(nums))))
                        nums[nums.index(max(nums))] -= 1
                else:
                    prov = max(nums)
                    result.write(chr(ord("A") + nums.index(max(nums))))
                    nums[nums.index(max(nums))] -= 1
                    if nums.count(prov) == 1:
                        result.write(chr(ord("A") + nums.index(max(nums))))
                        nums[nums.index(max(nums))] -= 1
                    result.write(" ")
            result.write("\n")
                                     
