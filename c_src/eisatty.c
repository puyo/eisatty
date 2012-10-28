#include "erl_nif.h"
#include <unistd.h>

// Prototypes
static ERL_NIF_TERM eisatty_detect(ErlNifEnv* env, int argc,
                               const ERL_NIF_TERM argv[]);

static ErlNifFunc nif_funcs[] =
{
    {"detect", 0, eisatty_detect}
};

static ERL_NIF_TERM eisatty_detect(ErlNifEnv* env, int argc,
                                   const ERL_NIF_TERM argv[])
{
   if(isatty(STDOUT_FILENO)) {
        return enif_make_atom(env, "true");
    } else {
        return enif_make_atom(env, "false");
    }    
}


static int on_load(ErlNifEnv* env, void** priv_data, ERL_NIF_TERM load_info)
{
    return 0;
}

ERL_NIF_INIT(eisatty, nif_funcs, &on_load, NULL, NULL, NULL);
