USE [master]
GO
/****** Object:  Database [GunManager]    Script Date: 2021/8/20 16:00:14 ******/
CREATE DATABASE [GunManager]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'GunManager', FILENAME = N'D:\Software\SQL2019\MicrosoftSQLServer\MSSQL15.MSSQLSERVER\MSSQL\DATA\GunManager.mdf' , SIZE = 270336KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'GunManager_log', FILENAME = N'D:\Software\SQL2019\MicrosoftSQLServer\MSSQL15.MSSQLSERVER\MSSQL\DATA\GunManager_log.ldf' , SIZE = 335872KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
 WITH CATALOG_COLLATION = DATABASE_DEFAULT
GO
ALTER DATABASE [GunManager] SET COMPATIBILITY_LEVEL = 150
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [GunManager].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [GunManager] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [GunManager] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [GunManager] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [GunManager] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [GunManager] SET ARITHABORT OFF 
GO
ALTER DATABASE [GunManager] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [GunManager] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [GunManager] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [GunManager] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [GunManager] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [GunManager] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [GunManager] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [GunManager] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [GunManager] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [GunManager] SET  DISABLE_BROKER 
GO
ALTER DATABASE [GunManager] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [GunManager] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [GunManager] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [GunManager] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [GunManager] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [GunManager] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [GunManager] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [GunManager] SET RECOVERY FULL 
GO
ALTER DATABASE [GunManager] SET  MULTI_USER 
GO
ALTER DATABASE [GunManager] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [GunManager] SET DB_CHAINING OFF 
GO
ALTER DATABASE [GunManager] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [GunManager] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [GunManager] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [GunManager] SET ACCELERATED_DATABASE_RECOVERY = OFF  
GO
EXEC sys.sp_db_vardecimal_storage_format N'GunManager', N'ON'
GO
ALTER DATABASE [GunManager] SET QUERY_STORE = OFF
GO
USE [GunManager]
GO
/****** Object:  Table [dbo].[allrule-less]    Script Date: 2021/8/20 16:00:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[allrule-less](
	[ID] [float] NULL,
	[Material] [nvarchar](255) NULL,
	[MaterialGroup] [nvarchar](255) NULL,
	[MaskedMPN] [nvarchar](255) NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[BoxPackedDetailsTable]    Script Date: 2021/8/20 16:00:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[BoxPackedDetailsTable](
	[序号] [int] NOT NULL,
	[装箱单号] [nvarchar](50) NOT NULL,
	[装备代码] [nvarchar](50) NOT NULL,
	[装备名称] [nvarchar](50) NOT NULL,
	[单装编号] [nvarchar](50) NULL,
	[缺失情况] [nvarchar](50) NULL,
	[出库状态] [nvarchar](50) NOT NULL,
	[记录时间] [datetime] NOT NULL,
 CONSTRAINT [PK_BoxPackedDetailsTable] PRIMARY KEY CLUSTERED 
(
	[序号] ASC,
	[装箱单号] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[BoxPackedTable]    Script Date: 2021/8/20 16:00:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[BoxPackedTable](
	[退役报废文件号] [nvarchar](50) NOT NULL,
	[调拨凭证号] [nvarchar](50) NOT NULL,
	[装箱单号] [nvarchar](50) NOT NULL,
	[装备代码] [nvarchar](50) NULL,
	[装备名称] [nvarchar](50) NULL,
	[隶属单位] [nvarchar](50) NULL,
	[管理单位] [nvarchar](50) NULL,
	[出厂时间] [date] NULL,
	[装备时间] [date] NULL,
	[装箱数量] [int] NULL,
 CONSTRAINT [PK_BoxPackedTable] PRIMARY KEY CLUSTERED 
(
	[退役报废文件号] ASC,
	[调拨凭证号] ASC,
	[装箱单号] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[SinglePackedTable]    Script Date: 2021/8/20 16:00:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[SinglePackedTable](
	[退役报废文件号] [nvarchar](50) NOT NULL,
	[调拨凭证号] [nvarchar](50) NOT NULL,
	[装备代码] [nvarchar](50) NOT NULL,
	[装备名称] [nvarchar](50) NOT NULL,
	[单装编号] [nvarchar](50) NULL,
	[隶属单位] [nvarchar](50) NOT NULL,
	[管理单位] [nvarchar](50) NOT NULL,
	[出厂时间] [date] NOT NULL,
	[装备时间] [date] NOT NULL,
	[出库状态] [nvarchar](50) NOT NULL,
	[记录时间] [datetime] NOT NULL,
 CONSTRAINT [PK_SinglePackedTable] PRIMARY KEY CLUSTERED 
(
	[退役报废文件号] ASC,
	[调拨凭证号] ASC,
	[装备代码] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[UserTable]    Script Date: 2021/8/20 16:00:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[UserTable](
	[姓名] [nvarchar](10) NOT NULL,
	[军官证号] [nvarchar](20) NOT NULL,
	[密码] [nvarchar](50) NULL,
	[识别操作] [bit] NOT NULL,
	[识别监督] [bit] NOT NULL,
	[入库操作] [bit] NOT NULL,
	[入库监督] [bit] NOT NULL,
	[出库操作] [bit] NOT NULL,
	[出库监督] [bit] NOT NULL,
 CONSTRAINT [PK_UserTable] PRIMARY KEY CLUSTERED 
(
	[姓名] ASC,
	[军官证号] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
USE [master]
GO
ALTER DATABASE [GunManager] SET  READ_WRITE 
GO
