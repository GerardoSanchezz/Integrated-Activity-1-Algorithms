# Repository for Algorithmic Problem Solving - Integrated Activity 1

In this repository, we tackled a complex problem involving the analysis of transmission codes and malicious codes, and determining the relations between them. To address this challenge, we implemented three different algorithms, each tailored to solve a specific task.

## Problem 1: Analyzing Transmission and Malicious Codes

The first task involved finding instances of malicious code within the transmission codes and identifying their starting positions. For this, we employed the Knuth-Morris-Pratt (KMP) algorithm due to its efficiency in handling pattern matching. The KMP algorithm preprocesses an array to store the longest prefix substring in the pattern (malicious code), enabling the algorithm to skip unnecessary comparisons upon encountering a mismatch. This results in fewer computations compared to the brute force algorithm, significantly improving performance. The time complexity of the KMP algorithm is O(n + m), where n represents the length of the text being analyzed and m represents the length of the pattern.

## Problem 2: Finding the Longest Mirrored Code

In the second task, we aimed to find the longest mirrored (palindromic) code within the transmission codes. To accomplish this, we utilized the Manacher's algorithm, known for its intelligent approach to exploiting palindrome properties. Manacher's algorithm efficiently determines the expansion length of palindromes centered at each index, leveraging the symmetry of palindromes to avoid redundant expansions. This approach significantly reduces the time complexity to O(n), as opposed to the naive implementation with a time complexity of O(n^3).

## Problem 3: Longest Common Subsequence (LCS)

The third task involved displaying the longest common substring between two stream files. To achieve this, we implemented the Longest Common Subsequence (LCS) algorithm, known for its effectiveness in finding common subsequences between strings. The time complexity of the LCS algorithm is O(m * n), where m and n represent the lengths of the input strings. We optimized our implementation by utilizing a hashmap to conserve memory space, as the traditional implementation incurred significant memory overhead by storing unnecessary values in the matrix. Our hashmap-based implementation only stores essential values, thus reducing memory consumption.

This repository contains the implementations of these algorithms, along with documentation and sample data for testing purposes.

Thank you for visiting this repository! If you have any questions or suggestions, feel free to reach out.
