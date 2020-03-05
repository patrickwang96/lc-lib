
int binary_search(const int arr[], int start, int end, int key) {
    int ret = -1;       // 未搜索到数据返回-1下标
    
	int mid;
	while (start <= end) {
		mid = start + (end - start) / 2; //直接平均可能會溢位，所以用此算法
		if (arr[mid] < key)
			start = mid + 1;
		else if (arr[mid] > key)
			end = mid - 1;
		else {            // 最後檢測相等是因為多數搜尋狀況不是大於要不就小於
			ret = mid;  
            break;
        }
	}
	
	return ret;     // 单一出口
}