#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <QString>
#define MAX_POOLS (32)
#define DEF_RPC_URL		"http://127.0.0.1:8332/"

#undef unlikely
#undef likely
#if defined(__GNUC__) && (__GNUC__ > 2) && defined(__OPTIMIZE__)
#define unlikely(expr) (__builtin_expect(!!(expr), 0))
#define likely(expr) (__builtin_expect(!!(expr), 1))
#else
#define unlikely(expr) (expr)
#define likely(expr) (expr)
#endif

void applog(int prio, const char *fmt, ...);

static int opt_n_threads;
static int num_processors;

#define PROGRAM_NAME		"anonplus-bitcoin-miner 0.001"

#define DEF_RPC_URL		"http://127.0.0.1:8332/"
#define DEF_RPC_USERNAME	"rpcuser"
#define DEF_RPC_PASSWORD	"rpcpass"
#define DEF_RPC_USERPASS	DEF_RPC_USERNAME ":" DEF_RPC_PASSWORD


#endif // GLOBAL_H
