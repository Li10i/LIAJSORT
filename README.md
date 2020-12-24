# LIAJSORT
#
# The fourth O(N)(to my knowledge after counting sort,Radix sort and package sort)
# algorithm and the fastest algorithm for big inputs(>1000000)
#
# It seems to look like an improved of the counting sort(even if I want to clarify 
# that the idea did not come to me from).
#
# The idea is to put in their "correct places" on the bits of an integer 
# the numbers in entries.
#
# The input numbers may be greater than the 32bits of a normal integer.
# To solve this problem we use a dynamic array whose size is increase and then
# we make each range of 32 values correspond to a box in the array 
# (t [0] = [0;31], t [1] = [32;64], ..... t [n] = [32n;32(n + 1)])
#
# Also we use two dynamic arrays: one for positive numbers 
# and another one for negative numbers.
#
# Thus,the algorithm passes at most once on each number of the table .So
# we have a complexity in O(n).
#
# In practice the algorithm is more efficient when the data are larger and larger.
# 
# For comparison the QUICKSORT is faster than the LIAJSORT for entries < 300k. 
# But from entries > 300k the LIAJSORT become faster and faster 
# (for entries = 300k , 0.3s for QS agaisnt 0.299s for LS
# but for entries = 10^7, 14s for Qs agaisnt 2s for LS)
#
# Appart from his good times complexity the LIAJSORT gives the advantages of
# the space complexity.
#
# For example,the algorithm use a little bit less than 30k integers (120k bytes)
# for a 10^6 inputs size(4*10^6*bytes).
#
# So enjoy the algorithm :-p ...





