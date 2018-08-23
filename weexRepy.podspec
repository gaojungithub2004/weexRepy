#
# Be sure to run `pod lib lint weexRepy.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'weexRepy'
  s.version          = '0.1.1'
  s.summary          = 'A short description of weexRepy.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/gaojungithub2004/weexRepy'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'gaojungithub2004' => 'gaojun2004@icloud.com' }
  s.source           = { :git => 'https://github.com/gaojungithub2004/weexRepy.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = 'weexRepy/Classes/**/*'
  
  # s.resource_bundles = {
  #   'weexRepy' => ['weexRepy/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  s.dependency 'AFNetworking', '~> 3.0'
  s.dependency 'WeexSDK'

  s.subspec 'DownFile' do |ss|
    ss.source_files  = "DownFile/*.{c,h,m,mm,S}"
    ss.public_header_files = "DownFile/*.h"
    ss.requires_arc  = true
  end
end
