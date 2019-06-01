//基于Partition函数解决的三个问题
/*1.快速排序算法*/
void quickSort(vector<int> &nums, int begin, int end)
{

    if (begin >= end) return;

    int index = partition(nums, begin, end);
    if (index>begin)
        quickSort(nums, begin, index-1);
    if (index<end)
        quickSort(nums, index+1, end);
}
/*2.数组中出现次数超过一半的数字*/
int MoreThanHalfNum_Solution(vector<int> numbers) 
{
    int length = numbers.size();
    if (numbers.empty() || length<0)
        return 0;

    int begin = 0;
    int end = length - 1;
    int middle = length >> 1;
    int index = 0; 
    //利用
    while (begin<end)
    {
        index = Partition(numbers, begin, end);
        if (index == middle)
        {
            break;
        }
        else if (index > middle)
        {
            end = index - 1; //则值在左边部分的数组。
        }
        else
        {
            begin = index + 1;//则值在右边部分的数组。
        }
    }
    //检查该值是否超过数组长度的一半
    int cnt = 0;
    for (int i = 0; i < length; ++i)
    {
        if (numbers[index] == numbers[i])
            cnt++;
    }
    if (cnt * 2 > length) return numbers[index];

    return 0;
}
/*3.最小的K个数*/
int Partition(vector<int> &nums, int begin, int end)
{
    int pivot = nums[begin];//第一个记录作为枢轴(也可是在begin和end之间的随机数)
    while (begin < end)
    {
        while (begin < end && nums[end] >= pivot)
        {
            end--;
        }
        nums[begin] = nums[end];//尾部找到小于pivot的值,移到低端

        while (begin < end && nums[begin] <= pivot)
        {
            begin++;
        }
        nums[end] = nums[begin];//头部找到大于pivot的值,移到高端
    }

    nums[begin] = pivot;//枢轴基准归位

    return begin;
}


vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {

    int len=input.size();
    if(len==0||k>len ||k<0) return vector<int>();
    if(len==k) return input;

    int start=0;
    int end=len-1;
    int index=Partition(input,start,end);
    while(index!=(k-1))
    {
        if(index>k-1)
        {
            end=index-1;
            index=Partition(input,start,end);
        }
        else
        {
            start=index+1;
            index=Partition(input,start,end);
        }
    }

    vector<int> res(input.begin(), input.begin() + k);

    return res;
}