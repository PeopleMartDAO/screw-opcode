/*
   +----------------------------------------------------------------------+
   | Screw Opcode                                                         |
   +----------------------------------------------------------------------+

*/

#ifndef ZEND_ACCELERATOR_BLACKLIST_H
#define ZEND_ACCELERATOR_BLACKLIST_H

typedef struct _zend_regexp_list zend_regexp_list;

typedef struct _zend_blacklist_entry {
    char *path;
    int path_length;
    int id;
} zend_blacklist_entry;

typedef struct _zend_blacklist {
    zend_blacklist_entry *entries;
    int size;
    int pos;
    zend_regexp_list *regexp_list;
} zend_blacklist;

typedef int (*blacklist_apply_func_arg_t)(zend_blacklist_entry *, zval *);

extern zend_blacklist accel_blacklist;

void zend_accel_blacklist_init(zend_blacklist *blacklist);

void zend_accel_blacklist_shutdown(zend_blacklist *blacklist);

void zend_accel_blacklist_load(zend_blacklist *blacklist, char *filename);

zend_bool zend_accel_blacklist_is_blacklisted(zend_blacklist *blacklist, char *verify_path, size_t verify_path_len);

void zend_accel_blacklist_apply(zend_blacklist *blacklist, blacklist_apply_func_arg_t func, void *argument);

#endif /* ZEND_ACCELERATOR_BLACKLIST_H */
