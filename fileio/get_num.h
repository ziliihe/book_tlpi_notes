#ifndef GET_NUM_H
#define GET_NUM_H

#define GN_NONNEG 01  /* >= 0 非负 */
#define GN_GT_0   02  /* >  0 正数 */

#define GN_ANY_BASE 0100  /* like strol(3) */
#define GN_BASE_8   0200  /* 八进制 */
#define GN_BASE_16  0400  /* 十六进制 */

long getLong(const char *arg, int flags, const char *name);

int getInt(const char *arg, int flags, const char *name);

#endif