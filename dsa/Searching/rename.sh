find . -depth -name "*.txt" -exec sh -c 'f="{}"; mv -- "$f" "${f%.txt}.c"' \;
