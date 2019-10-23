
make fclean
make clean
rm -rf */*.DS_Store
git add .
git commit -m "$1"
git push
echo "\n\n\n"
git status
echo "\n\n\n"