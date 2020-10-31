# Function to find amount of water that can be trapped within
# given set of bars in linear time and constant space
def trap(heights):

	# maintain two pointers left and right pointing to leftmost and
	# rightmost index of the input list
	(left, right) = (0, len(heights) - 1)
	water = 0

	maxLeft = heights[left]
	maxRight = heights[right]

	while left < right:
		if heights[left] <= heights[right]:
			left = left + 1
			maxLeft = max(maxLeft, heights[left])
			water += (maxLeft - heights[left])
		else:
			right = right - 1
			maxRight = max(maxRight, heights[right])
			water += (maxRight - heights[right])

	return water


# Trapping Rain Water within given set of bars
if __name__ == '__main__':

	heights = [7, 0, 4, 2, 5, 0, 6, 4, 0, 5]
	print("Maximum amount of water that can be trapped is", trap(heights))
