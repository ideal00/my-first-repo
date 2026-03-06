# my-first-repo
学习记录
1. vector动态数组
   头文件；#include <vector> 
   定义；vector<类型> arr
   访问；arr.at()
   尾部添加；arr.push_back()
   指定插入；arr.insert(arr.begin()+位置, 插入值)
   尾部删除；arr.pop_back()
   指定删除；arr.earse(arr.begin()+位置)
   清空元素；arr.clear()
   获取第一个元素；	vec.front()
   获取最后一个元素；	int last = vec.back()
   获取长度；vec.size()
   判断是否为空；	bool empty = vec.empty();	空返回 true，否则 false

2. 范围 for 循环
   vector	        for (int val : vec) { ... }	你之前写链表时用的场景，遍历所有元素
   string	        for (char c : str) { ... }	遍历字符串的每个字符（字符串本质是字符容器）
   array（固定数组）	for (int val : arr) { ... }	C++11 新增的固定大小数组，比普通数组安全
   list（链表）	     for (int val : lst) { ... }	遍历双向链表的每个元素
   map/unordered_map	for (auto& pair : mp) { ... }	遍历键值对（pair.first是键，pair.second是值）
   set/unordered_set	for (int val : st) { ... }	遍历集合的每个元素

3. 条件表达式 a = () ? 表达式1 : 表达式2;

4. 哑结点
   创建：dummy = new ListNode(0); dummy->next = head;（给头节点加前驱）；
   遍历：cur = dummy，通过cur->next操作所有节点（统一逻辑）；
   收尾：取出dummy->next作为新头，释放哑节点（避免泄漏）。