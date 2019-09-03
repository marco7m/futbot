script_start_a="./scripts/play_saved_game data/referee/training"
script_start_b="-*/gen_"
script_end="-*"
command="${script_start_a}$1${script_start_b}$2${script_end}"
echo $command
eval $command
