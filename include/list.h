#ifndef LIST_INCLUDED__
#define LIST_INCLUDED__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#ifdef __cplusplus
#define T List_T*
#else
#define T List_T
typedef struct T *T;
#endif
struct List_T {
	struct List_T* rest;
	void *first;
};
extern T      List_append (T list, T tail);
extern T      List_copy   (T list);
extern T      List_list   (void *x, ...);
extern T      List_pop    (T list, void **x);
extern T      List_push   (T list, void *x);
extern T      List_reverse(T list);
extern int    List_length (T list);
extern void   List_free   (T *list);
extern void   List_map    (T list, void apply(void **x, void *cl), void *cl);
extern void **List_toArray(T list, void *end);
#undef T

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* LIST_INCLUDED__ */
