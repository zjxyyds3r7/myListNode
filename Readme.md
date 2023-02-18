# 简单的int链表实现 没用模板 作者:周景鑫 微信:zjxyyds0307
1. 类名  
   ListNode  
2. 类变量
   - val :值
   - noxt:下一位指针
3. 构造函数
   - 默认构造 接受一个参数或者无参创建
   - 通过vector数组创建
   - 通过标准数组与数组大小创建
4. 成员函数
   - createNext  
  创建下一个链表节点 并返回新创建的节点

   - getIndex  
  返回index位的节点的值 错误返回d的值

   - insert  
  在index位置上插入val节点返回val节点所应的指针  

   - del  
  删除index下标下的节点 返回删除的下一个节点  

   - printAll  
  打印链表里所有元素  

   - serachValue  
  搜索val值的节点下标 没找到返回-1

