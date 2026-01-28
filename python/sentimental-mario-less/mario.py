height = 0
while (height < 1 or height > 8):
    try:
        height = (int(input("Height: ")))
    except ValueError:
        continue

# Spaces and hashes
for line in range(height):
    print(" " * (height - line - 1) + "#" * (1 + line))
