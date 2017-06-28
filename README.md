# eisatty

Erlang wrapper for `isatty(3)`.

Usage (Erlang):

```erlang-repl
1> eisatty:isatty(0).
true
2> eisatty:isatty(1).
true
3> eisatty:isatty(2).
true
4> eisatty:isatty(3).
false
```

Usage (Elixir):

Add to your `mix.exs`

```elixir
{:eisatty, github: "puyo/eisatty"}
```

Run `iex -S mix`

```elixir
iex> :eisatty.isatty(0)
true
iex> :eisatty.isatty(1)
true
iex> :eisatty.isatty(2)
true
iex> :eisatty.isatty(3)
false
```
