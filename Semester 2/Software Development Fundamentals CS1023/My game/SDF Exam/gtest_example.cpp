
#include <iostream>
#include <vector>
#include <array>
#include <gtest/gtest.h>

using namespace std;

void sort_array(array<int,5>& arr)
{
    for(int i =0;i < sizeof(arr)/sizeof(int) -1 ; i++)
    {
        for(int j = i + 1; j < sizeof(arr)/sizeof(int); j++)
        {
            if(arr[i] > arr[j])
            {
                std::swap(arr[i],arr[j]);
            }
        }
    }
}

TEST(SORTEST,Already_Sorted)
{
    array<int,5> arr = {490,3,2,1,0};
    
    sort_array(arr);
    size_t s = sizeof(arr)/sizeof(int);
    
    for(int i =0; i< s-1 ;i++)
    {
        EXPECT_LE(arr[i],arr[i+1]);
    }
}

int main(int argc,char** argv)
{
    ::testing::InitGoogleTest(&argc,argv);

    array<int,5> arr = {1,3,2,78,-9};
    
    sort_array(arr);
    
    for(auto a : arr)
    {
        cout << a << endl;
    }
    
    return RUN_ALL_TESTS();
    
    
}
