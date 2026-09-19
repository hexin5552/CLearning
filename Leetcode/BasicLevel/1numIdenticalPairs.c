/**
 * @author Hexin
 * @version 1.0
 */
int numIdenticalPairs(int* nums, int numsSize);
int main(void) {
    return 0;
}
int numIdenticalPairs(int* nums, int numsSize) {
    int *fast, *slow;
    /*fast = nums + 1;
    * fast 指针仅在循环开始前初始化为 nums + 1。
    * 外层循环每迭代一次，slow 向后移动一位，但内层循环的 fast 没有被重置。
    * 第一次外层循环时，fast 遍历完整个数组剩余部分，结束后 fast == nums + numsSize。
    * 后续外层循环中，内层循环的条件 fast < nums + numsSize 永远为假，因此只比较了第一个元素与后面所有元素，遗漏了其他元素之间的配对。
     */
    slow = nums;
    int total = 0;
    for(; slow < nums + numsSize; slow++) {
        fast = slow + 1;
        for(; fast < nums + numsSize; fast++)
            if(*fast == *slow)
                total++;
    }
    return total;
}