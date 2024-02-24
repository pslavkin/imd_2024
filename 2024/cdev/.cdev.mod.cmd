savedcmd_/repo/imd_2024/2024/cdev/cdev.mod := printf '%s\n'   cdev.o | awk '!x[$$0]++ { print("/repo/imd_2024/2024/cdev/"$$0) }' > /repo/imd_2024/2024/cdev/cdev.mod
