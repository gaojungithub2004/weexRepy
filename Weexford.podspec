# coding: utf-8

Pod::Spec.new do |s|
  s.name         = "Weexford"
  s.version      = "0.0.1"
  s.summary      = "Weex Plugin"

  s.description  = <<-DESC
                   Weexplugin Source Description
                   DESC

  s.homepage     = "https://github.com"
  s.license = {
    :type => 'Copyright',
    :text => <<-LICENSE
            copyright
    LICENSE
  }
  s.authors      = {
                     "frod" =>"gaojun2004@icloud.com"
                   }
  s.platform     = :ios
  s.ios.deployment_target = "8.0"

  s.source       = { :git => 'https://github.com/gaojungithub2004/weexford.git', :tag => s.version.to_s }
  s.source_files  = "ios/Sources/*.{h,m,mm}"
  
  s.requires_arc = true
  
  s.subspec 'DownFile' do |ss|
    ss.source_files  = "ios/Sources/DownFile/**/*.{h,m}"
    ss.frameworks    = "UIKit"
    ss.public_header_files = "ios/Sources/DownFile/**/*.{h}"
    ss.requires_arc  = true
    ss.dependency "WeexPluginLoader"
    ss.dependency "WeexSDK"
    ss.dependency "AFNetworking"
  end

  s.subspec 'Else' do |ss|
    ss.source_files  = "ios/Sources/Else/*.{h,m}"
    ss.frameworks    = "UIKit"
    ss.public_header_files = "ios/Sources/Else/*.{h}"
    ss.requires_arc  = true
  end
end
