
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
  ..
  
  
  
 2. //使用git命令遇到公钥问题时。
  重新更新秘钥。
  
  问题重现：
  guocepan@LAPTOP-3SIJU11J MINGW64 /e/myGitcode/myErro (master)
  
$ git push --set-upstream origin master  //
git@github.com: Permission denied (publickey).//权限被拒绝
fatal: Could not read from remote repository.//严重的：无法从远端库中读取，remote repository：远程仓库。

Please make sure you have the correct access rights
and the repository exists.//请保证你有权限和这个远程库存在。


解决：
问题分析：
这个是需要重新生成秘钥。将电脑上的秘钥和网上的秘钥进行重新匹配。

1，查看本机的用户名和邮箱是不是和网上设置的一致：
 
 
//guocepan@LAPTOP-3SIJU11J MINGW64 /e/myGitcode/myErro (master)
$ git config user.name
guocepan

//guocepan@LAPTOP-3SIJU11J MINGW64 /e/myGitcode/myErro (master)
$ git config user.email
1203543128@qq.com

确定完后进行生成秘钥操作

2.生成新的秘钥；
//guocepan@LAPTOP-3SIJU11J MINGW64 /e/myGitcode/myErro (master)

$ ssh-keygen -t rsa -C "1203543128@qq.com" //就是刚刚查到的邮箱
Generating public/private rsa key pair.
Enter file in which to save the key (/c/Users/guocepan/.ssh/id_rsa):
/c/Users/guocepan/.ssh/id_rsa already exists.
Overwrite (y/n)?// 这是问是否要覆盖   y
  // (/c/Users/guocepan/.ssh/id_rsa)   这个是秘钥生成的地方。使用命令行不方便，直接界面操作。
//找到这个位置，在中文状态下对应的位置如下
// >此电脑>Windows（c：）>用户>guocepan>.ssh   找到id_rsa.pub 用记事本打开，复制里面的内容。

来到网上：
3.  点击头像，找到setings这个选项

找到
SSH  and GPG keys这个选项，
选择
new SSH key
 
出现的界面要我们输入
标题  ： 可以随便写
和
key ：刚刚在本地复制的东西，然后点击 Add SSH key
成功后就出现一个选项框里出现了一把钥匙，和一堆东西。


在电脑端上验证的命令是：
guocepan@LAPTOP-3SIJU11J MINGW64 /e/myGitcode/myErro (master)
$ ssh -T git@github.com
Hi guocepan! You've successfully authenticated, but GitHub does not provide shell access.

这样就表示你已经成功了。

可以配合网址看：
https://blog.csdn.net/qq_34291777/article/details/55052201



