#!/usr/bin/python3
"""1. Two Sum"""


def twoSum(self, nums: List[int], target: int) -> List[int]:
    """Given an array of integers nums and an integer target,
    return indices of the two numbers such that they add up to target."""
    dict1 = {}
    for i in range(len(nums)):
        if target - nums[i] in dict1:
            return [i, dict1[target - nums[i]]]
        dict1[nums[i]] = i
    return [0,0]
