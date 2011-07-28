#include "global.h"


void applog(int prio, const char *fmt, ...)
{
    // TODO: Improve this log
    std::cout << fmt << std::endl;
}

static void initializeStatic()
{
#ifdef WIN32
    if (!opt_n_threads)
            opt_n_threads = 1;
#else
    num_processors = sysconf(_SC_NPROCESSORS_ONLN);
    if (!opt_n_threads)
            opt_n_threads = num_processors;
#endif /* !WIN32 */
}
