//Problem Description:Search element in a nearly sorted array,ith element may be present at ith,(i-1)th or (i+1)th position
#include<bits/stdc++.h>
int search(int arr[],int n,int x)
{
    int l = 0;
    int r = n - 1;
    while(l<=r){
        int mid = (l+r)>>1;
        if(arr[mid]==x) 
            return mid;
        else if(mid-1>=l && arr[mid-1]==x)
            return mid-1;
        else if(mid+1<n && arr[mid+1]==x)
            return mid+1;
        else if(arr[mid] > x)
            r = mid - 2;
        else 
            l = mid + 2;
    }
    return -1;
}