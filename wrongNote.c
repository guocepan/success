
1.说明，在push上去时发生这个错误：证书的问题。
guocepan@LAPTOP-3SIJU11J MINGW64 /e/myGitcode/c_plus_plus (master)
$ git push -u origin master -f
fatal: unable to access 'https://github.com/guocepan/c_plus_plus.git/': error setting certificate verify locations:
  CAfile: E:/git_install/Git/mingw64/ssl/certs/ca-bundle.crt
  CApath: none


解决办法：忽略证书：
guocepan@LAPTOP-3SIJU11J MINGW64 /e/myGitcode/c_plus_plus (master)

$ git config --system http.sslVerify false
这样就忽略掉了。
