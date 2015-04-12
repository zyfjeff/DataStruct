import os
env = Environment()  # Initialize the environment

root_path = os.getcwd()
thirdparty = str(root_path) + "/../thirdparty/"
common = str(root_path) + "/../common/"

env.Append(CPPPATH = [root_path, thirdparty, common,
           thirdparty + '/boost/include/',
           thirdparty + '/thrift/include/',
           thirdparty + '/glog/include/',
           thirdparty + '/gflags/include/',
           thirdparty + '/gtest/include/',
           thirdparty + 'sqlite/include/',
           thirdparty + '/tinyxml/',
           thirdparty + '/libevent/include/',
           thirdparty + '/libunwind/include/',
           ])

env.Append(LIBPATH = [thirdparty + '/boost/lib/', common,
           thirdparty + '/thrift/lib',
           thirdparty + '/glog/lib',
           thirdparty + '/gflags/lib',
           thirdparty + '/gtest/lib',
           thirdparty + '/sqlite/lib',
           thirdparty + '/tinyxml',
           thirdparty + '/libevent/lib',
           thirdparty + '/libunwind/lib',
           root_path + "/rpc/master",
           root_path + "/rpc/agent"
           ])

env.Append(LIBS = ['common', 'thriftnb', 'thrift', 'glog', 'gtest', 'event', 'gflags'
           , 'boost_filesystem', 'boost_thread', 'boost_system', 'boost_date_time'
           , 'sqlite3', 'tinyxml', 'pthread','dl', 'z', 'unwind', 'lzma'])

#'unwind', 'lzma', do not work for me(renzhen).

env.Append(CCFLAGS = ['-Wall', '-O2', '-g', '-Wno-unused-but-set-variable'
           , '-Wno-unused-local-typedefs','-DTIXML_USE_STL'])

env.Append(LINKFLAGS = ['-static'])
Export('env')

SConscript(['rpc/SConscript'], exports = 'env')

SConscript(['master/SConscript'], exports = 'env')
SConscript(['agent/SConscript'], exports = 'env')

SConscript(['tools/SConscript'], exports = 'env')
