#
#  Be sure to run `pod spec lint YuntxIMLib.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  s.name         = "YuntxLib"
  s.version      = "5.5.1.1"
  s.summary      = "容联云通讯 SDK(如果看不到最新版本，请使用 pod repo update 命令更新一下本地pod仓库)"

  # This description is used to generate tags and improve search results.
  #   * Think: What does it do? Why did you write it? What is the focus?
  #   * Try to keep it short, snappy and to the point.
  #   * Write the description between the DESC delimiters below.
  #   * Finally, don't worry about the indent, CocoaPods strips it!
  s.description  = <<-DESC
                  容联云通讯SDK YuntxLib. (如果看不到最新版本，请使用 pod repo update 命令更新一下本地pod仓库)
                   DESC

  s.homepage     = "https://www.yuntongxun.com/"
  # s.screenshots  = "www.example.com/screenshots_1.gif", "www.example.com/screenshots_2.gif"


  # ―――  Spec License  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Licensing your code is important. See http://choosealicense.com for more info.
  #  CocoaPods will detect a license file if there is a named LICENSE*
  #  Popular ones are 'MIT', 'BSD' and 'Apache License, Version 2.0'.
  #

  s.license      = "MIT"
  s.author             = { "lixiaojie" => "14971467480@163.com" }
  s.ios.deployment_target = "8.0"
  s.source       = { :git => "https://github.com/RLYuntongxun/YuntxLib.git", :tag => "#{s.version}" }
  s.resources  = "sdk/CCPSDKBundle.bundle"

  s.source_files = "sdk/*.h"
  s.vendored_library = 'sdk/*.a'
  s.libraries    = "resolv.9","icucore","sqlite3","z","xml2","bz2.1.0","c++"
  s.framework    = "CoreTelephony","MediaPlayer","CFNetwork","SystemConfiguration","MobileCoreServices","AudioToolbox","AVFoundation","VideoToolbox"

  s.subspec 'Delegate' do |ss|
  ss.source_files = "sdk/Delegate/*.h"
  end

  s.subspec 'enums' do |ss|
  ss.source_files = "sdk/enums/*.h"
  end

  s.subspec 'Manager' do |ss|
  ss.source_files = "sdk/Manager/*.h"
  end

  s.subspec 'private' do |ss|
  ss.source_files = "sdk/private/*.h"
  end

  s.subspec 'types' do |ss|
  ss.source_files = "sdk/types/*.h"

  ss.subspec 'LiveChatRoomType' do |sss|
  sss.source_files = "sdk/types/LiveChatRoomType/*.h"
  end
  end

  s.subspec 'board' do |ss|
  ss.source_files = "sdk/board/*.h"
  end


  s.requires_arc = true

  # s.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  # s.dependency "JSONKit", "~> 1.4"
  s.xcconfig = {
      'OTHER_LINKER_FLAGS' => '-ObjC',
      'ENABLE_BITCODE' => 'NO'
    }

end
