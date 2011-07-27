#include "minerclass.h"


MinerClass::MinerClass(QObject *parent) :
    QObject(parent),
    pools_active(0),
    total_tv_start(QDateTime::currentMSecsSinceEpoch ()),
    total_tv_end(QDateTime::currentMSecsSinceEpoch ())
{
#ifdef WIN32
    pt_n_threads = num_processors = 1;
#else
    num_processors = sysconf(_SC_NPROCESSORS_ONLN);
    opt_n_threads = num_processors;
#endif /* !WIN32 */

    // TODO: make this variable.
    qint8 total_threads = 2;


}
