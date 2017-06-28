#include "erl_nif.h"
#include <unistd.h>
#include <stdio.h>

ERL_NIF_TERM mk_atom(ErlNifEnv* env, const char* atom);
ERL_NIF_TERM mk_error(ErlNifEnv* env, const char* mesg);

ERL_NIF_TERM
mk_atom(ErlNifEnv* env, const char* atom)
{
  ERL_NIF_TERM ret;
  if(!enif_make_existing_atom(env, atom, &ret, ERL_NIF_LATIN1))
  {
    return enif_make_atom(env, atom);
  }
  return ret;
}

ERL_NIF_TERM
mk_error(ErlNifEnv* env, const char* mesg)
{
  return enif_make_tuple2(env, mk_atom(env, "error"), mk_atom(env, mesg));
}

static ERL_NIF_TERM
eisatty(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  int fd = STDIN_FILENO;

  if(argc != 1)
  {
    return enif_make_badarg(env);
  }

  if(!enif_is_number(env, argv[0]))
  {
    return enif_make_badarg(env);
  }

  enif_get_int(env, argv[0], &fd);

  if(isatty(fd) == 1)
  {
    return mk_atom(env, "true");
  }
  else
  {
    return mk_atom(env, "false");
  }
}

static ErlNifFunc nif_funcs[] = {
  {"isatty", 1, eisatty}
};

ERL_NIF_INIT(eisatty, nif_funcs, NULL, NULL, NULL, NULL);
