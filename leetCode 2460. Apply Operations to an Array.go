func applyOperations(nums []int) []int {
	sorted_nums := []int{}
	zero_count := 0
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] == nums[i+1] {
			nums[i] = nums[i] * 2
			nums[i+1] = 0
		}
	}
	for i := 0; i < len(nums); i++ {
		if nums[i] != 0 {
			sorted_nums = append(sorted_nums, nums[i])
		} else {
			zero_count++
		}
	}
	for i := 0; i < zero_count; i++ {
		sorted_nums = append(sorted_nums, 0)
	}
	return sorted_nums
}