Pod::Spec.new do |spec|

  spec.name         = "AKTalkSDK"
  spec.version      = "2.1.6"
  spec.license      = { :type => 'MIT', :file => 'LICENSE' }

  spec.summary      = "A lightweight scanning component based on system API in Swift5"
  spec.description  = <<-DESC
             No memory leaks, Support scaling, Support light sense to automatically turn on the flash, Support auto zoom, Support custom UI.
                      DESC

  spec.author             = { "zhongbin" => "zhongbin.wen@akuvox.com" }
  spec.homepage     = "https://github.com/Akuvox/AKTalkSDK"
  spec.source = { :git => 'https://github.com/Akuvox/AKTalkSDK.git', :tag => spec.version.to_s }

  spec.requires_arc = true

  spec.platform      = :ios, "12.0"
  spec.ios.deployment_target = "12.0"

  spec.static_framework = false

  spec.ios.vendored_frameworks = 'AKTalkSDK/AKTalkSDK.framework'
  spec.source_files = 'AKTalkSDK/**/*.h' # 确保路径正确
  spec.public_header_files = 'AKTalkSDK/AKTalkSDK.framework/Headers/*.h' # 确保路径正确
  # 添加以下行以排除 arm64 架构
  spec.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
    'SWIFT_OPTIMIZATION_LEVEL' => '-Onone',
    'SWIFT_VERSION' => '5.0',
    'VALID_ARCHS' => 'x86_64 armv7 arm64'
  }
end
