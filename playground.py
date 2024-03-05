

from src.main import main

# main([
#   "examples/example.c",
#   "--debug", "1",
# ])

# main([
#   "examples/sv-benchmarks/termination-crafted-lit/HeizmannHoenickeLeikePodelski-ATVA2013-Fig7.c",
#   "--function", "main",
#   "--debug", "2",
# ])

main([
  "examples/sv-benchmarks/termination-crafted-lit",
  "--function", "main",
  "--debug",
  "--output", "tmp/sv.json",
  "--dev-no-exception-traceback",
  # "--dev-stop-at-first-exception"
])

# main([
#   "examples/bignum/",
#   "--output", "tmp/bignum.json",
#   # "--dev-no-exception-traceback",
# ])
