// Please see:
// https://github.com/davisp/nif-examples

#include "erl_nif.h"

// Load is called when the NIF library is loaded and no previously
// loaded library exists for this module.
//
// Return value of 0 indicates success.
// Docs: http://erlang.org/doc/man/erl_nif.html#load

static int
load(ErlNifEnv* env, void** priv, ERL_NIF_TERM load_info)
{
    return 0;
}

// Called when changing versions of the C code for a module's NIF
// implementation if I read the docs correctly.
//
// Return value of 0 indicates success.
// Docs: http://erlang.org/doc/man/erl_nif.html#upgrade

static int
upgrade(ErlNifEnv* env, void** priv, void** old_priv, ERL_NIF_TERM load_info)
{
    return 0;
}

// Called when the library is unloaded. Not called after a reload
// executes.
//
// No return value
// Docs: http://erlang.org/doc/man/erl_nif.html#load

static void
unload(ErlNifEnv* env, void* priv)
{
    return;
}

// The actual C implementation of an Erlang function.
//
// Docs: http://erlang.org/doc/man/erl_nif.html#ErlNifFunc

static ERL_NIF_TERM
minicerl(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    return enif_make_badarg(env);
}

static ErlNifFunc nif_funcs[] = {
    {"minicerl", 1, minicerl}
};

// Initialize this NIF library.
//
// Args: (MODULE, ErlNifFunc funcs[], load, reload, upgrade, unload)
// Docs: http://erlang.org/doc/man/erl_nif.html#ERL_NIF_INIT

ERL_NIF_INIT(minicerl, nif_funcs, &load, NULL, &upgrade, &unload);

// Or if you don't need reload, upgrade, or unload.
// ERL_NIF_INIT(minicerl, nif_funcs, &load, NULL, NULL, NULL);
