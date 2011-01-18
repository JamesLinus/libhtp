/*
 * LibHTP (http://www.libhtp.org)
 * Copyright 2009,2010 Ivan Ristic <ivanr@webkreator.com>
 *
 * LibHTP is an open source product, released under terms of the General Public Licence
 * version 2 (GPLv2). Please refer to the file LICENSE, which contains the complete text
 * of the license.
 *
 * In addition, there is a special exception that allows LibHTP to be freely
 * used with any OSI-approved open source licence. Please refer to the file
 * LIBHTP_LICENSING_EXCEPTION for the full text of the exception.
 *
 */

#ifndef _HOOKS_H
#define	_HOOKS_H

#include "dslib.h"

#ifdef _HTP_H
#define HOOK_ERROR      HTP_ERROR
#define HOOK_OK         HTP_OK
#define HOOK_DECLINED   HTP_DECLINED
#else
#define HOOK_ERROR      -1
#define HOOK_OK          0
#define HOOK_DECLINED    1
#endif

typedef struct htp_hook_t htp_hook_t;
typedef struct htp_callback_t htp_callback_t;
typedef int (*htp_callback_fn_t) (void *);

#ifdef __cplusplus
extern "C" {
#endif

struct htp_hook_t {
    list_t *callbacks;
};

struct htp_callback_t {
    htp_callback_fn_t fn;
};

 int hook_register(htp_hook_t **hook, htp_callback_fn_t callback_fn);
 int hook_run_one(htp_hook_t *hook, void *data);
 int hook_run_all(htp_hook_t *hook, void *data);

htp_hook_t *hook_create(void);
htp_hook_t *hook_copy(htp_hook_t *hook);
       void hook_destroy(htp_hook_t *hook);


#ifdef __cplusplus
}
#endif

#endif	/* _HOOKS_H */

