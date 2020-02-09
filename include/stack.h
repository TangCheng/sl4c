#ifndef STACK_INCLUDED__
#define STACK_INCLUDED__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#ifdef __cplusplus
#define T Stack_T*
struct Stack_T;
#else
#define T Stack_T
typedef struct T *T;
#endif
extern T     Stack_new  (void);
extern int   Stack_empty(T stk);
extern void  Stack_push (T stk, void *x);
extern void *Stack_pop  (T stk);
extern void  Stack_free (T *stk);
#undef T

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* STACK_INCLUDED__ */
