vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int result = -1;
    vector<int> range;

    int L = 0, R = A.size()-1;
    while(L <= R)
    {
        int mid = (L+R)/2;

        if(A[mid] == B)
        {
            result = mid;
            R = mid - 1;
        }
        else if(B > A[mid])
            L = mid + 1;
        else if(B < A[mid])
            R = mid - 1;
    }
    range.push_back(result);

    L = 0; R = A.size()-1; result = -1;

    while(L <= R)
    {
        int mid = (L+R)/2;

        if(A[mid] == B)
        {
            result = mid;
            L = mid + 1;
        }
        else if(B > A[mid])
            L = mid + 1;
        else if(B < A[mid])
            R = mid - 1;
    }

    range.push_back(result);

    return range;
}
