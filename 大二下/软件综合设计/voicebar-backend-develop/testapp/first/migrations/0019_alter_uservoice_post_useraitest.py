# Generated by Django 4.1 on 2022-08-19 17:39

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('first', '0018_user_avatar_url_userpost_ip_loc_alter_userimage_post_and_more'),
    ]

    operations = [
        # migrations.AlterField(
        #     model_name='uservoice',
        #     name='post',
        #     field=models.OneToOneField(on_delete=django.db.models.deletion.CASCADE, related_name='voice', to='first.userpost'),
        # ),
        # migrations.CreateModel(
        #     name='UserAITest',
        #     fields=[
        #         ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
        #         ('json_result', models.JSONField()),
        #         ('voice_url', models.URLField()),
        #         ('creator', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='first.user')),
        #     ],
        # ),
    ]
