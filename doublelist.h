/*
 =====================================================================================
        Filename:  doublelist.cpp
     	Description:  双向循环链表
        Version:  1.0
        Created:  28/02/15 20:39:42
        Revision:  none
        Compiler:  gcc
        Author:  Jeff (), zyfforlinux@163.com
    	Organization:  Linux
 =====================================================================================
 */

#ifndef _DOUBLELIST_H_
#define _DOUBLELIST_H_


struct doublelist {
	doublelist *prev;
	doublelist *next;
};

/*
 * 	 双向链表初始化,指向自身
 *
 */
#define doublelist_init(q) 			\
	(q)->prev = q;				\
	(q)->next = q;

/*
 * 	双向链表判断是否为空,prev是否等于自己
 *
 */
#define doublelist_empty(h)			\
	(h == (h)->prev)

/*
 * 	头插
 *
 */

#define doublelist_inert_head(h,x)		\
	(x)->next = (h)->next;			\
	(x)->next->prev = x;			\
	(x)->prev = h;				\
	(h)->next = x;

#define doublelist_inert_after	doublelist_inert_head

#define doublelist_insert_tail(h,x)		\
	(x)->prev = (h)->prev;			\
	(x)->prev->next = x;			\	
	(h)->prev = x;				\
	(x)->next = h;

#define doublelist_head(h)			\
	(h)->next

#define doublelist_last(h)			\
	(h)->prev;

#define doublelist_sentinel(h)			\
	(h)

#define doublelist_next(q)			\
	(q)->next;

#define doublelist_prev(q)			\
	(q)->prev;

#define doublelist_remove(x)			\
	(x)->next->prev = (x)->prev;		\
	(x)->prev->next = (x)->next;

#define doublelist_split(h,q,n)			\
	(n)->prev = (h)->prev;			\
	(n)->prev->next = n;			\
	(n)->next = q;				\
	(h)->prev = (q)->prev;			\
	(h)->prev->next = h;			\
	(q)->prev = n;

#define doublelist_add(h,n)			\
	(h)->prev->next = (n)->next;		\
	(n)->next->prev = (h)->prev;		\
	(h)->prev = (n)->prev;			\
	(h)->prev->next = h;

#define doublelist_data(q,type,link)		\
	(type *)((u_char *)q - offsetof(type,link))

#endif /*  _DOUBLELIST_H_INCLUDE_ */
