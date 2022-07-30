import java.util.*;
class Solution {
	private void swap(int []arr, int i, int j) {
		final int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	private int partition(int []arr, int low, int high) {
		System.out.println("Arr Bef: " + Arrays.toString(arr));
		int pivot = arr[high];
        int i = low;
        for(int j = low; j < high;++j)
        {
            if(arr[j] < pivot)
            {
                swap(arr,i,j);
                i++;
            }
        }
        swap(arr,i,high);
        return i;
	}

	public int findKthLargest(int []arr, int k) {
		int n = arr.length;
		int low = 0, high = n - 1;

		k = n - k;
		while (low < high) {
			int pivot = partition(arr, low, high);
			System.out.println("Arr : " + Arrays.toString(arr));
			if (pivot < k) {
				low = pivot + 1;
			} else if (pivot > k)
				high = pivot - 1;
			else
				break;
		}
		return arr[k];
	}

	public static void main(String[] args) {
		// int arr[] = {3, 2, 1, 5, 6, 4};
		// int arr[] = {7,6,5,4,3,2,1};
		// int arr[] = {3,2,5,4,1};
		int arr[] = {5,2,6,4,3,1};
		int k = 1;
		Solution t = new Solution();
		System.out.println(t.findKthLargest(arr, k));
	}
}


class Solution {
    public int findKthLargest(int[] nums, int k) {
        if (nums.length == 1) {
            return nums[0];
        }
        int start = 0;
        int end = nums.length - 1;
        k = nums.length - k;
        while (end - start > 5) {
            int pivot = medianOf3(nums, start, end);
            int i = start;
            int j = end - 1;
            while (true) {
                do {
                    i++;
                } while (nums[i] < pivot);
                do {
                    j--;
                } while (nums[j] > pivot);
                if (i < j) {
                    swap(nums, i, j);
                } else {
                    break;
                }
            }
            swap(nums, i, end - 1);
            if (i == k) {
                return nums[i];
            } else if (i < k) {
                start = i + 1;
            } else {
                end = i - 1;
            }
        }
        for (int i = start + 1; i <= end; i++) {
            for (int j = i - 1; j >= start; j--) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums, j, j + 1);
                } else {
                    break;
                }
            }
        }
        return nums[k];
    }
    private int medianOf3(int[] nums, int start, int end) {
        int mid = (start + end) / 2;
        if (nums[start] > nums[mid]) {
            swap(nums, start, mid);
        }
        if (nums[mid] > nums[end]) {
            swap(nums, mid, end);
        }
        if (nums[start] > nums[mid]) {
            swap(nums, start, mid);
        }
        swap(nums, mid, end - 1);
        return nums[end - 1];
    }
    
    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
}