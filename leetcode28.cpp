//寻找第一个匹配的子串，即kmp算法
#include<bits/stdc++.h>
using namespace std;
vector<int> generateNext(string t){
    int pos = 1;//当前部分匹配和的指针
    int len = 0;//当前部分匹配和的长度
    int sum = 0;
    vector<int> next(t.length());
    /*
    生成next数组的算法思想：
    用len记录当前部分匹配和的长度，同时len也是指向最长匹配前缀末尾元素的指针
    用pos记录当前生成next的元素，同时pos也是指向最长匹配后缀末尾元素的指针
    每当pos和len指向的元素相同时，该字母匹配成功，len向后移动的同时也说明匹配和增加
    每当pos和len指向的元素不同时，len要回到前一个元素对应的最长匹配后缀的末尾元素
    即len=next[len-1]
    当len回到0时，pos前缀匹配和为0
    */
    while (pos < t.length()){
        if (t[pos] != t[len]){
            if (len == 0) {
                next[pos] = 0;
                ++pos;}
            else len = next[len - 1];
        }
        else{
            ++len;
            next[pos] = len;
            ++pos;
        }
    }
    return next;
}
int kmp(string s, string t){
    vector<int> next = generateNext(t);
    int i = 0;
    int j = 0;
    while(i < s.length()){

        if (s[i] == t[j]){
            ++i;
            ++j;
            if (j == t.length()){
                return i - j;
            }
        }
        else{
            if (j == 0) i++;
            else j = next[j-1];
        }
    }
    return -1;
}
int main(){
    string aystack = "aaaababc";
    string needle = "ababc";
    cout<<kmp(aystack,needle);
    return 0;
}
