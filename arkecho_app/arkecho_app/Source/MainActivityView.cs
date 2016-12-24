using Android.App;
using Android.Widget;
using Android.OS;
using System.Threading.Tasks;

namespace arkecho_app
{
    [Activity(Label = "ArkEcho", MainLauncher = true, Icon = "@drawable/icon")]
    public class MainActivityView : Activity
    {
        MainActivityModel model_;

        protected override void OnCreate(Bundle bundle)
        {
            base.OnCreate(bundle);
            // Set our view from the "main" layout resource
            SetContentView (Resource.Layout.Main);

            FindViewById<Button>(Resource.Id.pbClickMe).Click += onPbClickMeClick;

            Websockets.Droid.WebsocketConnection.Link();

            model_ = new MainActivityModel();
        }

        private void onPbClickMeClick(object sender, System.EventArgs e)
        {
            model_.connectWebSocket("ws://192.168.178.20:1000");
        }
    }
}
