using System.Management;
using System.Net;


namespace totalLibrary.SystemInfo
{
    public class MainInfo
    {
        public static string GetOSName()
        {
            System.OperatingSystem os = System.Environment.OSVersion;
            string osName = "Unknown";


            switch (os.Platform)
            {
                case System.PlatformID.Win32Windows:
                    switch (os.Version.Minor)
                    {
                        case 0:
                            osName = "Windows 95";
                            break;
                        case 10:
                            osName = "Windows 98";
                            break;
                        case 90:
                            osName = "Windows ME";
                            break;
                    }
                    break;
                case System.PlatformID.Win32NT:
                    switch (os.Version.Major)
                    {
                        case 3:
                            osName = "Windws NT 3.51";
                            break;
                        case 4:
                            osName = "Windows NT 4";
                            break;
                        case 5:
                            if (os.Version.Minor == 0)
                                osName = "Windows 2000";
                            else if (os.Version.Minor == 1)
                                osName = "Windows XP";
                            else if (os.Version.Minor == 2)
                                osName = "Windows Server 2003";
                            break;
                        case 6:
                            osName = "Windows Vista";
                            break;
                    }
                    break;
            }

            return osName + ", " + os.Version.ToString();
        }
        public static string GetPCName()
        {
            string netBiosName = System.Environment.MachineName;
            string dnsName = System.Net.Dns.GetHostName();
            return dnsName;
        }
        public static string GetMac()
        {
            string Mac = string.Empty;
            ManagementClass MC = new ManagementClass("Win32_NetworkAdapter");
            ManagementObjectCollection MOCol = MC.GetInstances();
            foreach (ManagementObject MO in MOCol)
                if (MO != null)
                {
                    if (MO["MacAddress"] != null)
                    {
                        Mac = MO["MACAddress"].ToString();
                        if (Mac != string.Empty)
                            break;
                    }
                }
            return Mac;
        }
        public static string GetIp()
        {
            string strHostName = "";
            strHostName = System.Net.Dns.GetHostName();
            IPHostEntry ipEntry = System.Net.Dns.GetHostEntry(strHostName);
            IPAddress[] addr = ipEntry.AddressList;
            return addr[addr.Length - 1].ToString();
        }

    }
}
