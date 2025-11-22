/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func detectCycle(head *ListNode) *ListNode {
    if head==nil || head.Next==nil{
        return nil
    }
    slow:=head
    fast:=head
    for fast!=nil && fast.Next!=nil{
        slow=slow.Next
        fast=fast.Next.Next
        if slow==fast{
            break
        }
    }
    if fast==nil || fast.Next==nil{
        return nil
    }
    temp:=head
    for temp!=slow{
        temp=temp.Next
        slow=slow.Next
    }
    return temp

}