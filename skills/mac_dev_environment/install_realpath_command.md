brew install realpath, failed
brew insall coreutils, get this error log:
	Error: Cannot install coreutils because conflicting formulae are installed.
	  md5sha1sum: because both install `md5sum` and `sha1sum` binaries
	
	Please `brew unlink md5sha1sum` before continuing.
try to run `brew unlink md5sha1sum`, and then run `brew install coreutils` again, succeeded.

