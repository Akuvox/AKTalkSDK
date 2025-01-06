
Pod::Spec.new do |spec|

  spec.name         = "AKTalkSDK"
  spec.version      = "2.1.5"
  spec.license      = "MIT"

  spec.summary      = "A lightweight scanning component based on system API in Swift5"
  spec.description  = <<-DESC
             No memory leaks, Support scaling, Support light sense to automatically turn on the flash, Support auto zoom, Support custom UI.
                      DESC

  spec.author             = { "zhongbin" => "zhongbin.wen@akuvox.com" }
  spec.homepage     = "https://github.com/Akuvox/AKTalkSDK"
  spec.source = { :git => 'git@github.com:Akuvox/AKTalkSDK.git', :tag => spec.version.to_s }

  spec.requires_arc = true

  spec.platform      = :ios, "12.0"
  spec.ios.deployment_target = "12.0"

  spec.static_framework = true
  spec.ios.vendored_frameworks = 'AKTalkSDK/AKTalkSDK.framework'
  spec.source_files = 'AKTalkSDK/AKTalkSDK.framework/Headers/*' # 或者根据需要调整路径
  spec.public_header_files = 'AKTalkSDK/AKTalkSDK.framework/Headers/*.h'


  # 添加以下行以排除 arm64 架构
  spec.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
    'SWIFT_OPTIMIZATION_LEVEL' => '-Onone'
  }



end
