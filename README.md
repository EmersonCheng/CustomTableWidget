# Demo 示例项目

Demo 项目是 Coding.net 为方便新用户了解其项目管理功能的一个快速通道，可以根据 项目中预设的任务来了解主要功能的操作流程。

用户可以在该项目中进行创建任务、发表讨论、上传文件、添加成员、提交代码、使用WebIDE、部署演示平台等操作。

## 代码介绍

本项目是一个简单的 PHP 程序，目录结构：

```
.
├── Procfile
├── composer.json
├── README.md
├── env.php
├── index.php
└── phpinfo.php
```

## 代码要求

根目录下必须存在 `index.php` 或 `composer.json` 文件。
部署演示平台需要`Procfile`文件。

## WebIDE

您可以进入WebIDE对代码进行编辑，省去了安装配置本地环境的繁琐，只需要一个浏览器就可以开始写代码，体验语法高亮、代码提示、Git管理、分享终端环境等强大功能。

WebIDE相关文档：https://coding.net/help/doc/webide/index.html

## 本地测试

将代码clone到本地目录后，在项目目录下执行 `php -S 0.0.0.0:8000` 启动服务器，访问 [http://localhost:8000](http://localhost:8000) 即可以预览效果。

## 演示平台

我们已经为您配置好，在演示平台中只需点击一键部署。稍等片刻待部署完成后，通过域名即可访问。

演示平台相关文档：https://coding.net/help/doc/paas/index.html