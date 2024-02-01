#!/usr/bin/python3
"""3. Longest Substring"""


def lengthOfLongestSubstring(self, s: str) -> int:
    """
    Given a string s, find the length of the longest 
    substring without repeating characters.
    """
    seen = {}
    start = maxLength = 0
    for i in range(len(s)):
        if s[i] in seen and start <= seen[s[i]]:  
            start = seen[s[i]] + 1 
        else: 
            maxLength = max(maxLength, i - start + 1)  
        seen[s[i]] = i
    return maxLength
