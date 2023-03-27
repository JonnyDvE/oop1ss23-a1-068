#!/bin/sh

# This script auto-commits and pushes the users code into separate branches.
# Such commits and pushes do not count as submission, so please make sure to
# commit and push your code as described in the task description.


repo_path="$(git rev-parse --show-toplevel)"
repo_url="$(git remote -v | awk '/origin/ { print $2 }' | head -n 1)"
branch="$(git branch --show-current)"


main() {
	# create repo for auto committing, if it does not exist yet
	if [ ! -d ~/.a1_auto ]
	then
		git clone "$repo_url" ~/.a1_auto
		cd ~/.a1_auto/
		git config --local user.name "Auto-Upload Script"
		git config --local user.email "auto-uploader@example.com"
	fi

	# switch to appropriate branch in the auto repo
	cd ~/.a1_auto
	git checkout "auto-$branch" || git checkout -b "auto-$branch"

	# copy files over
	cp -r "$repo_path"/* "$HOME/.a1_auto/"

	# commit changes
	git add '*.h*' '*.c*'
	git commit -m "AUTOUPLOAD"
	git push --set-upstream origin "auto-$branch"
}
main >/dev/null 2>/dev/null
