Pod::Spec.new do |s|
  s.name = "UOASmartHomeSDK"
  s.version = "0.7.4"
  s.summary = "umeinfo open api"
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"andy90s"=>"909901234@qq.com"}
  s.homepage = "https://github.com/andy90s/UOASmartHome"
  s.description = "TODO: Add long description of the pod here."
  s.frameworks = ["CFNetwork", "CoreFoundation", "CoreTelephony", "SystemConfiguration", "CoreGraphics", "Foundation", "UIKit", "Security", "CoreData"]
  s.libraries = "icucore"
  s.requires_arc = true
  s.source = { :path => '.' }
  s.source = { :git => 'https://github.com/andy90s/UOASmartHome.git' }
  s.ios.deployment_target    = '8.0'
  s.ios.vendored_framework   = 'UOASmartHomeSDK.framework'
 s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
end
