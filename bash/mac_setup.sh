# Setup Homebrew on the system
ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

# Install useful Unix commands
brew install wget

# Install Emacs
brew install emacs --with-cocoa --srgb
ln -s /usr/local/Cellar/emacs/24.5/Emacs.app /Applications

# Install Python and useful libraries
brew install python
brew install python3
brew tap homebrew/python
brew install numpy
brew install scipy
pip2 install requests
pip3 install requests

#brew tap homebrew/tex 
