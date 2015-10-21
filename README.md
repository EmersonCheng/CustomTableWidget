# Demo 示例项目

Demo 项目是 coding 为方便新用户了解项目管理功能的一个快速通道。
用户可以根据 Demo 项目中的功能点提示来快速了解每一个功能的操作流程，并且该项目的所有人归属用户本人。
用户可以在该项目中进行任务指派、发表讨论、上传文件、添加成员、提交代码、演示平台、WebIDE等操作。

PS：该项目不支持更改项目名称、项目转让功能。

## 代码介绍

本项目是一个简单的 PHP 程序，目录结构：

```
.
├── README.md
├── env.php
├── index.php
└── phpinfo.php
```

## 项目要求

根目录下必须存在 `index.php` 或 `composer.json` 文件。


## WebIDE

你可以进入WebIDE对代码进行编辑，省去了安装配置本地环境的繁琐，只需要一个浏览器就可以开始写代码，体验语法高亮、代码提示、Git管理、分享终端环境等强大功能。


WebIDE相关文档：https://coding.net/help/doc/webide/index.html

## 本地测试

将代码clone到本地目录后，在目录下执行 `php -S 0.0.0.0:8000` 启动服务器，访问 [http://localhost:8000](http://localhost:8000) 即可以预览效果。

## 演示平台

示例项目默认已开启演示平台，可点击[http://zhimaxiaoren-demo.coding.io](http://zhimaxiaoren-demo.coding.io)进行访问。


演示平台相关文档：https://coding.net/help/doc/paas/index.html