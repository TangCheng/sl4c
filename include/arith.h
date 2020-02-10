#ifndef ARITH_H__
#define ARITH_H__

#ifdef __cplusplus
extern "C" {
#endif

int Arith_max(int x, int y);
int Arith_min(int x, int y);
int Arith_div(int x, int y);
int Arith_mod(int x, int y);
int Arith_ceiling(int x, int y);
int Arith_floor(int x, int y);

#ifdef __cplusplus
}
#endif

#endif /* ARITH_H__ */